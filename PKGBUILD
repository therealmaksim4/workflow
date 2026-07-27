# Maintainer: therealmaksim4 <maksim.budim11052013@gmail.com>
pkgname="workflow"
pkgver=0.1.5
pkgrel=9
pkgdesc="Enhance your coding"
arch=("x86_64")
url="https://github.com/therealmaksim4/workflow"
license=("GPL")
depends=("luajit")
makedepends=("git" "cmake>=3.16")
source=("workflow::https://github.com/therealmaksim4/workflow.git")
md5sums=("SKIP")

prepare() {
    cd ..

    mkdir -p ~/.config/workflow
    rm -rf ~/.config/workflow/lua
    cp -r ~/workflow/src/lua

    rm -rf build
    mkdir build
}

build() {
    cd ..

    cmake -S . -B build
    cmake --build build
}

package() {
    cd ..

    sudo cmake --install build
}
