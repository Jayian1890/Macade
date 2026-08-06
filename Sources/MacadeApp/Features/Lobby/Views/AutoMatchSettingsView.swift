import SwiftUI

struct AutoMatchSettingsView: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    private var configuration: FightcadeAutoMatchConfiguration {
        viewModel.autoMatchConfiguration(for: channel)
    }

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            header

            settingStepper(
                title: "Invite batch",
                value: configuration.maxChallengesPerAttempt,
                range: 1...5,
                step: 1,
                suffix: "invites"
            ) { update(maxChallengesPerAttempt: $0) }

            settingStepper(
                title: "Rotate timeout",
                value: configuration.acceptanceTimeoutSeconds,
                range: 10...120,
                step: 5,
                suffix: "sec"
            ) { update(acceptanceTimeoutSeconds: $0) }

            settingStepper(
                title: "Rank tolerance",
                value: configuration.rankTolerance,
                range: 0...5,
                step: 1,
                suffix: "ranks"
            ) { update(rankTolerance: $0) }

            settingStepper(
                title: "Max ping",
                value: configuration.maximumPing,
                range: 50...300,
                step: 10,
                suffix: "ms"
            ) { update(maximumPing: $0) }

            Divider()

            Button("Reset Defaults") {
                viewModel.resetAutoMatchConfiguration(for: channel)
            }
            .buttonStyle(.plain)
            .font(MacadeTypography.caption)
            .foregroundStyle(MacadeColor.warning)
        }
        .padding(MacadeSpacing.large)
        .frame(width: 290)
        .background(MacadeColor.panelStrong)
    }

    private var header: some View {
        VStack(alignment: .leading, spacing: 4) {
            Text("Auto Match")
                .font(.system(size: 15, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)

            Text(channel.title)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
                .lineLimit(1)
        }
    }

    private func settingStepper(
        title: String,
        value: Int,
        range: ClosedRange<Int>,
        step: Int,
        suffix: String,
        update: @escaping (Int) -> Void
    ) -> some View {
        Stepper(value: Binding(
            get: { value },
            set: { update($0) }
        ), in: range, step: step) {
            HStack {
                Text(title)
                    .foregroundStyle(MacadeColor.ink)
                Spacer()
                Text("\(value) \(suffix)")
                    .font(.system(size: 11, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.neonCyan)
            }
            .font(MacadeTypography.caption)
        }
    }

    private func update(
        maxChallengesPerAttempt: Int? = nil,
        acceptanceTimeoutSeconds: Int? = nil,
        rankTolerance: Int? = nil,
        maximumPing: Int? = nil
    ) {
        let current = configuration
        viewModel.updateAutoMatchConfiguration(FightcadeAutoMatchConfiguration(
            maxChallengesPerAttempt: maxChallengesPerAttempt ?? current.maxChallengesPerAttempt,
            acceptanceTimeoutSeconds: acceptanceTimeoutSeconds ?? current.acceptanceTimeoutSeconds,
            rankTolerance: rankTolerance ?? current.rankTolerance,
            maximumPing: maximumPing ?? current.maximumPing,
            retryCooldownSeconds: current.retryCooldownSeconds
        ), for: channel)
    }
}
