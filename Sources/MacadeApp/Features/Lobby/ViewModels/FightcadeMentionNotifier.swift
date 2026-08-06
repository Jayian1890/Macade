import AppKit
import UserNotifications

enum FightcadeMentionNotifier {
    static func notify(message: FightcadeChatMessage) {
        if NSSound(named: "Ping")?.play() != true {
            NSSound.beep()
        }

        Task {
            let center = UNUserNotificationCenter.current()
            let settings = await center.notificationSettings()
            let isAuthorized: Bool

            switch settings.authorizationStatus {
            case .authorized, .provisional, .ephemeral:
                isAuthorized = true
            case .notDetermined:
                isAuthorized = (try? await center.requestAuthorization(options: [.alert, .sound])) == true
            case .denied:
                isAuthorized = false
            @unknown default:
                isAuthorized = false
            }

            guard isAuthorized else {
                return
            }

            let content = UNMutableNotificationContent()
            content.title = "Mention from \(message.username)"
            content.subtitle = message.channelName
            content.body = message.body
            content.sound = .default

            let request = UNNotificationRequest(
                identifier: "macade-mention-\(message.id.uuidString)",
                content: content,
                trigger: nil
            )

            try? await center.add(request)
        }
    }
}
