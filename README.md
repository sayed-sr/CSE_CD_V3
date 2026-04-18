# Smart Home Automation Rule Engine
### A Lex + Yacc (Bison) Compiler Project

---

## Project Description

This project implements a **domain-specific rule language** for a smart home automation system using **Lex** (lexical analysis) and **Yacc/Bison** (syntax analysis and semantic actions).

Users write automation rules in a simple, readable language. The compiler parses these rules and executes them — controlling virtual devices like lights, fans, AC, alarms, cameras, and more based on sensor readings and conditions.

---

## Features

| Feature | Description |
|---|---|
| **Lexical Analysis** | Lex tokenizes keywords, operators, and sensor/device names |
| **Grammar Rules** | Yacc grammar handles if/then/else, scene shortcuts, assignments |
| **Device Control** | 8 devices: Light, Fan, AC, Heater, Alarm, Camera, Sprinkler, Door |
| **Sensor Simulation** | 6 sensors: Temperature, Humidity, Motion, Smoke, Door, Time |
| **If/Else Rules** | Full conditional branching with `if ... then ... else ... end` |
| **Scene Shortcuts** | Preset scenes: `scene morning`, `scene night`, `scene normal` |
| **Emergency Override** | `emergency` keyword triggers all safety systems at once |
| **AST Printing** | Every rule prints its AST node for educational visibility |
| **Event Log** | All device changes are logged; `log` command prints history |
| **Status Dashboard** | `status` command prints all device and sensor states |
| **Comments** | Lines starting with `#` are ignored |
| **Case Insensitive** | Keywords work in any case (`ON`, `on`, `On` all valid) |

---

## File Structure

```
smarthome/
├── smarthome.l      ← Lex file (lexer / tokenizer)
├── smarthome.y      ← Yacc file (parser + semantic actions)
├── Makefile         ← Build automation
├── input1.txt       ← Demo: Morning routine + temperature control
├── input2.txt       ← Demo: Fire emergency + night security
├── input3.txt       ← Demo: Simple if/else scenario
└── README.md        ← This file
```

---

## Language Syntax

### Sensor Assignment
```
temp = 35
humidity = 70
motion = detected
smoke = clear
door = open
time = night
```

### Device Control (direct)
```
set light on
set fan off
set ac on
set alarm on
lock door
unlock door
```

### If / Then / Else
```
if temp > 30 then
    set ac on
    set fan on
end

if motion == detected then
    set camera on
else
    set camera off
end
```

### Supported Conditions
| Condition | Example |
|---|---|
| Temperature comparison | `temp > 30`, `temp < 18`, `temp == 25` |
| Humidity comparison | `humidity > 65`, `humidity < 40` |
| Motion state | `motion == detected`, `motion == clear` |
| Smoke detection | `smoke == detected` |
| Door sensor | `door == open`, `door == closed` |
| Time of day | `time == morning`, `time == night`, `time == day` |

### Scene Shortcuts
```
scene morning    # Lights ON, door unlocked, camera ON
scene night      # Lights OFF, fan ON, door locked, camera ON
scene normal     # All devices reset to OFF
```

### Emergency Override
```
emergency        # Alarm ON, sprinklers ON, cameras ON, door unlocked
```

### Utility Commands
```
status           # Print all device + sensor states
log              # Print event history
# This is a comment
```

---

## How to Build & Run

### Prerequisites
- `flex` (Lex)
- `bison` (Yacc)
- `gcc`

**Install on Ubuntu/Debian:**
```bash
sudo apt-get install flex bison gcc
```

**Install on Fedora/RHEL:**
```bash
sudo dnf install flex bison gcc
```

### Build
```bash
make
```

### Run with demo inputs
```bash
make run1    # Morning routine scenario
make run2    # Fire emergency + night security scenario
make run3    # Simple if/else demo
```

### Run interactively
```bash
./smarthome
```
Then type rules and press `Ctrl+D` when done.

### Run with your own file
```bash
./smarthome < your_rules.txt
```

### Clean build files
```bash
make clean
```

---

## Sample Output (input3.txt)

```
╔══════════════════════════════════════╗
║  Smart Home Automation Rule Engine   ║
║  Lex + Yacc Compiler Project         ║
╚══════════════════════════════════════╝

Parsing rules...

  AST: (sensor -> temp=val)
  → 🌡️  Temperature set to 28°C
  AST: (sensor -> time=night)
  → 🌙 Time set to NIGHT
  AST: (sensor -> motion=detected)
  → 👁️  Motion sensor: DETECTED
  AST: (if_stmt -> condition+then+else)
  ✔ Condition TRUE: temp(28) > 25
  → ❄️  AC turned ON
  AST: (if_stmt -> condition+actions)
  ✔ Condition TRUE: motion == detected
  → 💡 Light turned ON
  → 📷 Camera activated
  AST: (scene -> night)
  → 🌙 Night Scene activated
  AST: (status -> print)

╔══════════════════════════════════════╗
║        DEVICE STATUS DASHBOARD       ║
║  💡 Light     : ON                  ║
║  ❄️  AC        : ON                  ║
║  📷 Camera    : ON                  ║
║  🚪 Door      : LOCKED              ║
╚══════════════════════════════════════╝
```

---

## Concepts Demonstrated

- **Lexical analysis** with Lex/Flex
- **Context-free grammar** definition in Yacc/Bison
- **Semantic actions** (device state changes, print output)
- **Global state management** across grammar rules
- **AST (Abstract Syntax Tree)** node printing
- **Operator tokens** (`==`, `!=`, `>`, `<`)
- **Multi-rule grammar** with if/else, scenes, sensor assignments
- **Priority / override rules** (emergency mode)

---

*Project built with Lex + Bison (GNU Flex 2.6 / GNU Bison 3.x)*
