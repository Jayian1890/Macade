#include "macade_ggpo_session.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static bool ResolveDirectPeer(const char* host, int port, sockaddr_in* out)
{
	if (host == NULL || host[0] == 0 || out == NULL || port <= 0) return false;
	memset(out, 0, sizeof(*out));
	out->sin_family = AF_INET;
	out->sin_port = htons((unsigned short)port);
	if (inet_pton(AF_INET, host, &out->sin_addr) == 1) return true;
	addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	addrinfo* result = NULL;
	if (getaddrinfo(host, NULL, &hints, &result) != 0 || result == NULL) return false;
	sockaddr_in resolved = *(sockaddr_in*)result->ai_addr;
	freeaddrinfo(result);
	out->sin_addr = resolved.sin_addr;
	return true;
}

bool MacadeEstablishDirectSession(GGPOSession* session, int localport, const char* remoteip, int remoteport)
{
	if (session == NULL) return false;
	if (!ResolveDirectPeer(remoteip, remoteport, &session->peer)) {
		MacadeLog("Macade GGPO: direct peer resolve failed host=%s port=%d\n", remoteip == NULL ? "" : remoteip, remoteport);
		return false;
	}
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd < 0) return false;
	sockaddr_in local;
	memset(&local, 0, sizeof(local));
	local.sin_family = AF_INET;
	local.sin_port = htons((unsigned short)(localport < 0 ? 0 : localport));
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (sockaddr*)&local, sizeof(local)) != 0) {
		MacadeLog("Macade GGPO: direct UDP bind failed local=%d\n", localport);
		close(fd);
		return false;
	}
	socklen_t localLen = sizeof(local);
	if (getsockname(fd, (sockaddr*)&local, &localLen) == 0) {
		MacadeLog("Macade GGPO: direct UDP bound local=%d peer=%s:%d\n", ntohs(local.sin_port), inet_ntoa(session->peer.sin_addr), ntohs(session->peer.sin_port));
	}
	session->udpFd = fd;
	session->hasPeer = true;
	return true;
}
