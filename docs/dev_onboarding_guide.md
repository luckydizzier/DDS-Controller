# Developer Onboarding Guide – DDS-Controller Project

Welcome to the DDS-Controller project. This guide is designed to help new developers get up and running quickly by providing essential information about the system, its structure, development process, and conventions.

---

## 🚀 Quick Start

1. **Clone the Repository**  
   `git clone https://github.com/<your-org>/dds-controller`

2. **Project Structure Overview**  
   Refer to `docs/design/project_structure.md` for the full directory breakdown.

3. **Setup Requirements**
   - Java JDK 17+ (for GUI tools)
   - PlatformIO (for Arduino Due and ESP8266 firmware)
   - Python 3.10+ (for utilities and validation scripts)
   - Go (for optional GUI/CLI PC tool)

4. **Build Targets**
   - `firmware/due/` – Arduino firmware with menu & DDS control
   - `firmware/esp/` – ESP8266 WiFi bridge
   - `pc/gui/` – Fyne-based GUI in Go
   - `pc/cli/` – Python-based CLI tool

---

## 👷‍♂️ Development Protocols

- Use agent-specific `AGENTS.md` files as your responsibility guide.
- Every file/folder has an assigned owner agent.
- Follow the prompt generation rules in `docs/dev_protocols/prompt_generation.md`.
- Tasks and milestones are in `TODO.md` and `MILESTONES.md`.
- All contributions are timestamped in `docs/progress/`.

---

## 🧠 Key Concepts

- **Agent-Based Development**: Each module is owned by an intelligent agent with a defined scope.
- **Prompt-Based Execution**: Prompts written in Markdown drive Codex-based generation.
- **Layered Architecture**: Separation of firmware, protocol, and PC tools.
- **ASCII Protocol**: Minimal, file-based command interface between MCUs and host.
- **REST API**: Optional HTTP interface for PC-level interaction.

---

## 📋 Coding Conventions

- All code and comments in English.
- UI labels in Hungarian.
- Follow formatting rules in `docs/styleguide.md`.
- Consistent naming and timestamping across logs and commits.

---

## 🆘 Need Help?

- Root agent: defined in root `AGENTS.md`
- Review all files in `docs/design/` and `docs/dev_protocols/`.
- For decision blockers, use `NEEDS_HUMAN_DECISION` in `TODO.md`.
- Communication via GitHub Issues or agent-generated logs.

Welcome aboard!
