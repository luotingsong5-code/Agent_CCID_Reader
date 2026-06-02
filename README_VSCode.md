# Agent_CCID_Reader VSCode 工程使用指南

本项目已为你配置好两种 VSCode 开发环境，你可以根据个人偏好选择：
1. **VSCode EIDE 模式 (推荐)**：使用本地 `arm-none-eabi-gcc` 编译器进行完全独立的编译、高亮与调试，脱离 Keil 依赖。
2. **Keil 助手模式 (备用)**：通过 VSCode 插件一键调用后台 Keil (UV4.exe) 进行编译与下载。

---

## 1. 推荐安装的 VSCode 插件

为了获得最佳开发体验，请在 VSCode 扩展商店安装以下插件：
1. **Embedded IDE (EIDE)** (由 cl.eide 提供) — *EIDE 编译必装*
2. **Cortex-Debug** (由 marus25 提供) — *调试必装*
3. **C/C++** (由 Microsoft 提供) — *代码提示与跳转*
4. **Keil Assistant** (由 xianyuwan 提供) — *如果需要使用 Keil 编译模式则安装*

---

## 2. 模式一：VSCode EIDE 模式 (使用 ARM GCC 编译)

### 2.1 打开方法
1. 在 VSCode 中，选择 **文件 -> 打开工作区 (Open Workspace from File...)**。
2. 选择并打开项目根目录下的 **`Agent_CCID_Reader.code-workspace`**。

### 2.2 工具链配置
项目默认配置的 GCC 路径为 `C:/Users/Administrator/.eide/tools/gcc_arm`。
* 如果你的 `arm-none-eabi-gcc` 安装在其他目录，请打开 `Agent_CCID_Reader.code-workspace`，修改 `"EIDE.ARM.GCC.InstallDirectory"` 的值，指向你的 GCC 编译器安装路径（注意斜杠使用 `/`）。

### 2.3 如何编译与烧录
1. 打开工作区后，VSCode 左侧侧边栏会显示 **EIDE** 的项目树。
2. 在 **EIDE** 视图中，你可以：
   * 点击右上角的 **Build** 按钮 (圆圈带有勾的图标) 或使用快捷键 `Ctrl+Alt+B` 进行编译。
   * 编译产物（`.elf`、`.hex`、`.bin` 等）将生成在根目录的 `build` 文件夹中。
   * 在 EIDE 视图的 **烧录配置** 中，已配置好使用 **JLink** 烧录，点击 **Flash** 按钮即可一键下载到芯片。
3. **链接脚本与启动文件**：
   * 针对 ARM GCC 编译，项目已自动在根目录创建了链接脚本 `stm32f103xe.ld`。
   * 同时在 `Core/Startup/startup_stm32f103xe.s` 创建了适用于 GCC 语法的汇编启动文件（排除了 Keil 专用的汇编文件）。

---

## 3. 模式二：Keil 助手模式 (使用 Keil 编译器)

如果你仍旧希望通过 Keil MDK (UV4.exe) 在 VSCode 中编译：
1. VSCode 左侧侧边栏会显示 Keil Assistant 的视图。
2. 插件会自动关联并加载 `MDK-ARM/Agent_CCID_Reader.uvprojx` 项目。
3. 你可以直接在侧边栏点击相应的 Build、Rebuild 或 Download 按钮进行构建。
4. **编译快捷键**：
   * 按下 `Ctrl + Shift + B` 会直接调用本地的 `C:\Keil_v5\UV4\UV4.exe` 完成构建。
   * 如果你的 Keil 安装路径不同，请在 `.vscode/tasks.json` 中修改对应的 `command` 绝对路径。
