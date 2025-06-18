prompt_generation.md – Standard Prompt Format Guide

📌 Purpose

This document defines the standard format for generating agent prompts across the DDS-Controller project. Prompts must be concise, deterministic, and machine-readable. They are used by ChatGPT Codex agents to execute implementation tasks.

🔠 Prompt Format

Each prompt must follow this minimal structure:

### Prompt Metadata
Agent: <agent_name>
Task: <short summary>
Target File(s): <relevant files to be generated/updated>
Related Docs: <design docs or specs to reference>

### Prompt Body
Implement the <feature/module/task> as described in <related docs>. Follow all patterns and conventions defined in the project. Use idiomatic code and include error handling where appropriate. Log all actions to `docs/progress/YYYY-MM-DD_HH-MM-SS_<agent>.md`.

✅ Example

Agent: firmware_agent
Task: Implement DDSDriver interface for AD9850
Target File(s): firmware/due/DDSDriver.cpp
Related Docs: docs/design/project_structure.md, docs/design/architecture_overview.md

### Prompt Body
Implement a class `DDSDriver` that allows initialization and control of an AD9850 module. Include methods for `init()`, `setFrequency(float freqHz)`, and `powerDown()`. Reference pinout in project_structure.md. Log completion to progress log.

🧭 Principles
	•	Minimalist: Avoid redundancy; Codex has context
	•	Atomic: One feature/task per prompt
	•	Traceable: Must reference design docs + log files
	•	Language: English only
	•	Style: Markdown for all prompt files

🧾 Prompt File Location

All generated prompts must be stored in:

prompts/YYYY-MM-DD_HH-MM-SS_<agent>_<task_name>.md


⸻

Maintainer: root_agent
Last Updated: 2025-06-18