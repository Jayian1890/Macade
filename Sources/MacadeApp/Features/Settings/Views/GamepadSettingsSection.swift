import SwiftUI

struct GamepadSettingsSection: View {
    @Bindable var settings: MacadeSettingsViewModel
    @State private var model = GamepadSettingsViewModel()

    var body: some View {
        SettingsSection(
            title: "Gamepad Bindings · FBNeo",
            subtitle: "Connect a gamepad or arcade stick, choose a game, then set its controls. Save and relaunch the game to apply."
        ) {
            VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                if let error = model.error {
                    Text(error).foregroundStyle(MacadeColor.warning)
                }
                devicePicker
                gamePicker
                if model.isLoading { ProgressView("Reading FBNeo controls…") }
                if let game = model.selectedGame {
                    Text("\(game.title) · \(game.id)").font(MacadeTypography.headline)
                    if !model.availablePlayers.isEmpty {
                        Picker("Local game player", selection: $model.player) {
                            ForEach(model.availablePlayers, id: \.self) { player in
                                Text("Player \(player)").tag(player)
                            }
                        }
                        .pickerStyle(.segmented)
                        Text("For Fightcade matches, configure Player 1 here: these are your local controls. The session assigns them to your match side. Other players are for local play. Spectating and replays do not use these bindings.")
                            .font(MacadeTypography.caption).foregroundStyle(MacadeColor.inkMuted)
                    }
                    ForEach(model.playerInputs) { input in bindingRow(input) }
                    if model.inputs.isEmpty, !model.isLoading {
                        Text("This driver exposes no player controls in the binding editor.")
                            .foregroundStyle(MacadeColor.inkMuted)
                    }
                    HStack {
                        Button("Restore FBNeo Bindings for This Player") { model.reset(settings: settings) }
                            .foregroundStyle(MacadeColor.warning)
                        Spacer()
                        if model.captureInput != nil {
                            Button("Cancel Capture") { model.cancelCapture() }
                        }
                    }
                }
                if let message = model.message {
                    Text(message).font(MacadeTypography.caption).foregroundStyle(MacadeColor.neonCyan)
                }
                Text("Buttons, stick directions, triggers, and D-pads can be captured directly. Analog game inputs require a stick axis. Stick directions activate beyond half travel. Press triggers fully to bind them; small stick movement is ignored. Bindings override FBNeo’s joystick binding for that action; keyboard bindings stay available. Restore removes only the Macade profile and preserves FBNeo’s game files.")
                    .font(MacadeTypography.caption).foregroundStyle(MacadeColor.inkMuted)
            }
        }
        .task { await model.start(settings: settings) }
        .onDisappear { model.stop() }
        .onChange(of: settings.savedSettingsGeneration) { _, _ in
            model.cancelCapture()
            model.message = nil
        }
    }

    @ViewBuilder private var devicePicker: some View {
        if model.devices.isEmpty {
            Text("No controller connected. Connect it by USB or pair it in macOS Bluetooth settings. Controllers appear here when SDL detects them.")
                .foregroundStyle(MacadeColor.inkMuted)
        } else {
            Picker("Controller", selection: $model.selectedDeviceID) {
                if model.selectedDevice == nil, !model.selectedDeviceID.isEmpty {
                    Text("Selected controller disconnected").tag(model.selectedDeviceID)
                }
                ForEach(model.devices) { device in
                    Text("\(device.name) · \(device.id.suffix(8))").tag(device.id)
                }
            }
        }
        if let device = model.selectedDevice {
            Text("Live input: \(device.controls.filter { !device.restingControls.contains($0) }.map(\.title).joined(separator: ", ").nilWhenEmpty ?? "Released")")
                .font(MacadeTypography.caption).foregroundStyle(MacadeColor.neonCyan)
            if !device.hasSerial {
                Text("This controller has no serial number. If using identical controllers, keep their connection order and check bindings after reconnecting. USB and Bluetooth may appear as separate devices.")
                    .font(MacadeTypography.caption).foregroundStyle(MacadeColor.inkMuted)
            }
        }
    }

    private var gamePicker: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            TextField("Find an FBNeo game by name or ROM ID", text: $model.search)
                .textFieldStyle(.roundedBorder)
            ForEach(model.matchingGames) { game in
                Button { model.select(game) } label: {
                    HStack {
                        Text(game.title).lineLimit(1)
                        Spacer()
                        Text(game.id).foregroundStyle(MacadeColor.inkMuted)
                    }
                }.buttonStyle(.borderless)
            }
            if model.selectedGame == nil {
                Text("Choose a game to see its actual FBNeo actions. You can configure bindings before launching or installing its ROM.")
                    .font(MacadeTypography.caption).foregroundStyle(MacadeColor.inkMuted)
            }
        }
    }

    private func bindingRow(_ input: GamepadGameInput) -> some View {
        let binding = model.binding(for: input, settings: settings)
        let isCapturing = model.captureInput?.index == input.index
        return HStack(spacing: MacadeSpacing.medium) {
            Text(input.title).frame(maxWidth: .infinity, alignment: .leading)
            if input.analog { Text("Analog axis").font(MacadeTypography.caption) }
            if isCapturing {
                Text(model.captureArmed ? "Press / move…" : "Release controls…")
                    .foregroundStyle(MacadeColor.neonCyan)
            } else if let binding {
                Text(binding.control?.title ?? "Unbound").foregroundStyle(MacadeColor.inkMuted)
                if binding.deviceID != model.selectedDeviceID {
                    Text("Other controller").font(MacadeTypography.caption)
                } else if let control = binding.control,
                          model.selectedDevice?.controls.contains(where: {
                              $0 == control || (control.kind == "x" && $0.kind == "a" && $0.index == control.index)
                          }) == true {
                    Image(systemName: "circle.fill").foregroundStyle(MacadeColor.neonCyan)
                        .accessibilityLabel("Input active")
                }
            } else {
                Text("FBNeo saved / default").foregroundStyle(MacadeColor.inkMuted)
            }
            Button("Set") { model.beginCapture(input) }.disabled(model.selectedDevice == nil)
            Button("Clear") { model.clear(input, settings: settings) }.disabled(model.selectedDevice == nil)
        }
    }
}

private extension String {
    var nilWhenEmpty: String? { isEmpty ? nil : self }
}
