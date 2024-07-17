# Installation

- [Create new project with KOWGUI template](#create-new-project-with-kowgui-template)
- [Add KOWGUI to an existing project](#add-kowgui-to-an-existing-project)
- [Update existing project to latest version of KOWGUI](#update-existing-project-to-latest-version-of-kowgui)

## Create new project with KOWGUI template

1. Download the latest template from [releases](https://github.com/ColbyPrescott/KOWGUI/releases).
2. Unzip and rename folder to be your own program.
3. Move folder to the default VEX VSCode Extension folder, `Documents/vex-vscode-projects`, or another destination.
4. Open folder in VSCode and start writing your own code.

## Add KOWGUI to an existing project

1. Download and unzip the latest version from [releases](https://github.com/ColbyPrescott/KOWGUI/releases).
2. Move `src/KOWGUI` into the `src` folder of your project, and
    `include/KOWGUI` into your `include` folder.  
3. Copy, paste, and replace the downloaded `makefile` into the root directory of your project.
    <details>
        <summary>Manual</summary>

        KOWGUI has many layers of subfolders which aren't built by default. Add these lines after the section repeating variants of `SRC_C += $(wildcard src/*/*.cpp)`:
        ```
        SRC_C += $(wildcard src/*/*/*.cpp)
        SRC_C += $(wildcard src/*/*/*.c)
        SRC_C += $(wildcard src/*/*/*/*.cpp) 
        SRC_C += $(wildcard src/*/*/*/*.c)```
    </details>
4. Copy, paste, and replace the downloaded `vex/mkenv.mk` into the `vex` folder of your project.
    <details>
        <summary>Manual</summary>

        KOWGUI uses `dynamic_cast`. This needs to be enabled by replacing the `-fno-rtti` compiler flag with `-frtti` inside `vex/mkenv.mk`, likely on line 95. 
    </details>
5. Start using KOWGUI by including the `KOWGUI/kowgui.h` header in any GUI-related files, creating a global instance of a `KOWGUI::GUI` object, then calling `GUI::Tick()` in a loop of your choice.

## Update existing project to latest version of KOWGUI

This will be written with the second version release. Stay tuned!