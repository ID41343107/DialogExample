# DialogExample - Calculator

A Qt-based calculator application without using .ui files.

## Features

### Basic Operations (Floating-Point)
- Addition (+)
- Subtraction (-)
- Multiplication (×)
- Division (÷)

### Additional Features
- Decimal point support for floating-point calculations
- Clear button (C) to reset the calculator
- Derivative button (d/dx) - demonstrates derivative of x² at current value
- Integration button (∫) - demonstrates integral of x² from 0 to current value

### UI Components
- Number buttons: 0-9
- Display: Shows current value/result
- All UI elements created programmatically (no .ui files)

## Implementation Details
- Built with Qt Widgets
- QDialog-based main window
- Grid layout for calculator buttons
- Supports floating-point arithmetic