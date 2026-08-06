extension AuthenticatedHomeViewModel {
    func autoMatchConfiguration(for channel: FightcadeChannel) -> FightcadeAutoMatchConfiguration {
        autoMatchConfiguration(for: channel.name)
    }

    func autoMatchConfiguration(for channelName: String) -> FightcadeAutoMatchConfiguration {
        if let configuration = autoMatchConfigurationsByChannel[channelName] {
            return configuration
        }

        let configuration = autoMatchConfigurationStore.configuration(for: session, channelName: channelName)
        autoMatchConfigurationsByChannel[channelName] = configuration
        return configuration
    }

    func updateAutoMatchConfiguration(_ configuration: FightcadeAutoMatchConfiguration, for channel: FightcadeChannel) {
        autoMatchConfigurationsByChannel[channel.name] = configuration
        autoMatchConfigurationStore.saveConfiguration(configuration, for: session, channelName: channel.name)
    }

    func resetAutoMatchConfiguration(for channel: FightcadeChannel) {
        updateAutoMatchConfiguration(.default, for: channel)
    }
}
