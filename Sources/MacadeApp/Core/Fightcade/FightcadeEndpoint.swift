import Foundation

enum FightcadeEndpoint {
    static let bootstrapURL = URL(string: "https://web.fightcade.com/api/")!
    static let publicAPIURL = URL(string: "https://web.fightcade.com/api/")!
    static let userStatusAPIURL = URL(string: "https://web.fightcade.com/fc2status/api/")!
    static let websocketURL = URL(string: "wss://ggs.fightcade.com/ws/")!
    static let userAgent = "Fightcade2-WIN32-v2.1.45"
    static let timeout: TimeInterval = 20
}
