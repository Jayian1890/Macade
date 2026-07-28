import Foundation

struct FightcadeBootstrapService: Sendable {
    private let session: URLSession

    init(session: URLSession = .shared) {
        self.session = session
    }

    func requestEncryptedLocation() async throws -> String {
        var request = URLRequest(url: FightcadeEndpoint.bootstrapURL)
        request.httpMethod = "POST"
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.setValue("application/json", forHTTPHeaderField: "Accept")
        request.httpBody = try JSONSerialization.data(withJSONObject: ["req": "location"])

        let (data, response) = try await session.data(for: request)
        try validateHTTPResponse(response)

        let payload = try decodeJSONObject(from: data)
        guard stringValue(in: payload, keys: ["res"]) == "OK",
              let location = stringValue(in: payload, keys: ["location"]),
              !location.isEmpty else {
            throw FightcadeServiceError.unexpectedResponse("Could not start login.")
        }

        return location
    }

    private func validateHTTPResponse(_ response: URLResponse) throws {
        guard let httpResponse = response as? HTTPURLResponse else {
            throw FightcadeServiceError.networkUnavailable
        }

        guard (200..<300).contains(httpResponse.statusCode) else {
            throw FightcadeServiceError.networkUnavailable
        }
    }

    private func decodeJSONObject(from data: Data) throws -> [String: Any] {
        guard let payload = try JSONSerialization.jsonObject(with: data) as? [String: Any] else {
            throw FightcadeServiceError.unexpectedResponse("Could not start login.")
        }

        return payload
    }

    private func stringValue(in dictionary: [String: Any], keys: [String]) -> String? {
        for key in keys {
            if let value = dictionary[key] as? String {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.stringValue
            }
        }

        return nil
    }
}
