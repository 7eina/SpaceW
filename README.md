# SpaceW

## Overiew
SpaceX dupe/simulation: Rocket parts performance, inspection, and maintenance platform. Tracks parts, rockets, installations, launches, and inspections in a space exploration context.

Created: Summer 2023

## Compatibility
- **Ubuntu**: This software is fully compatible with Ubuntu and can be compiled and executed in any standard Ubuntu environment.
- **VirtualBox Virtualizing Ubuntu on Windows**: The software can be run on Ubuntu virtualized through VirtualBox on a Windows host. Ensure that your VirtualBox setup has adequate resources allocated and Ubuntu installed for smooth operation.
- **CLion on Windows**: The project can be loaded and executed in the CLion IDE on Windows. This requires a C++ environment setup in CLion, including the MinGW or Cygwin toolchains.

## System Requirements
- **Linux**: GCC compiler and standard C++ libraries.
- **Windows**: CLion with MinGW or Cygwin, VirtualBox for virtualizing Linux.

## Files Included

- **defs.h**: Contains essential definitions.
- **Date.h/.cc**: Entity object that stores date information.
- **Part.h/.cc**: Virtual base class for all parts.
  - **LT_Part**: Entity object for parts that must be inspected after a certain number of launches.
  - **TT_Part**: Entity object for parts that require inspection after a specific period.
  - **LT_TT_Part**: Entity object for parts that require inspection after meeting certain launch and/or time thresholds.
- **Array.h**: Templated data structure, a container object.
- **Rocket.h/.cc**: Combines entity and container functionalities, storing rocket data and installed parts.
- **SpaceW.h/.cc**: Control object that manages parts, rockets, installations, launches, and inspections.
  
### Testing Modules

- **TestControl.h/.cc**
- **View.h/.cc**
- **main.cc**

## Compilation Instructions
1. Open a terminal in the assignment folder.
2. Enter the following command to compile the project:
   ```bash
   make

## Execution Instructiona
After compilation, execute the program with the following command:
   ```bash
   ./a4

