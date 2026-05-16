# lsfg-vk
Original Progect https://github.com/PancakeTAS/lsfg-vk.git
Lossless Scaling is a Windows-exclusive app with the goal of bringing frame generation (among other features) to every single game or app.

lsfg-vk brings this frame generation to Linux users by acting as a Vulkan layer inbetween your game and your graphics card.
____________________________________________________________
this fork lsfg-vk modification for devices with older Vulkan 1.2 drivers
Specific modification for TegraX1 Nintendo Switch

------------------------------------------------------------------------------------

Build instructions

debian

sudo apt install qt6-qpa-plugins libqt6quick6 qml6-module-qtquick-controls qml6-module-qtquick-layouts qml6-module-qtquick-window qml6-module-qtquick-dialogs qml6-module-qtqml-workerscript qml6-module-qtquick-templates qml6-module-qt-labs-folderlistmodel git curl llvm clang clang-tools clang-tidy cmake ninja-build pkg-config libvulkan-dev mesa-common-dev qt6-base-dev qt6-base-dev-tools qt6-tools-dev qt6-tools-dev-tools qt6-declarative-dev qt6-declarative-dev-tools

fedora

sudo dnf install qt6-qtdeclarative qt6-qtbase

Arch

sudo pacman -S qt6-declarative qt6-base
_________________________________________________________________
git clone https://github.com/masies-hack/lsfg-vk.git

cd lsfg-vk/

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=On

cmake --build build -j$(nproc)

sudo cmake --install build
_______________________________________________________________
edit

/usr/share/vulkan/implicit_layer.d/VkLayer_LS_frame_generation.json

Modifi line

"library_path": "liblsfg-vk.so",

for

"library_path": "/usr/local/lib/liblsfg-vk.so",

____________________________________________________________
sudo ldconfig

first launch has a dll error

VK_INSTANCE_LAYERS=VK_LAYER_LSVK_frame_generation vkcube
___________________________________________________________
on

~/.config/lsfg-vk/conf.toml

edit, uncoment Lossless.dll path line
especific Lossless.dll path
____________________________________________________________
then again

VK_INSTANCE_LAYERS=VK_LAYER_LSVK_frame_generation vkcube

it must work
____________________________________________________________
Once installed, open up the lsfg-vk Configuration Window which should hopefully appear in your application menu.

Please see the [Wiki](https://github.com/PancakeTAS/lsfg-vk/wiki) for more information and join the [Discord](https://discord.gg/losslessscaling) for help (needs Steam verification).

## Credits
Most of the project has still only been written by me, PancakeTAS, but I couldn't have done it without the help of these people:
- [0xNULLderef](https://github.com/0xNULLderef): Teaching me how to reverse engineer software.
- [Caliel666](https://github.com/Caliel666): Writing the initial draft of the user interface.
- [Samueru-sama](https://github.com/Samueru-sama): Helping with various things XDG as well as app images and testing.
- Other contributors: Thank you for your contribution!

I'd also like to thank every single person sponsoring this project. Thanks to you I'll be able to invest more time into this and hopefully bring some cool new features to everyone.
