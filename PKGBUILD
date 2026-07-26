# Maintainer: therealmaksim4 <maksim.budim11052013@gmail.com>
pkgname="workflow"
pkgver=0.1.0
pkgrel=3
pkgdesc="Enhance your coding"
arch=("x86_64")
url="https://github.com/therealmaksim4/workflow"
license=("GPL")
depends=("lua")
makedepends=("git" "cmake>=3.16")
source=("workflow::https://github.com/therealmaksim4/workflow.git")
md5sums=("SKIP")

build() {
    cd ..

    cmake -S . -B build
    cmake --build build
}

package() {
    cd ..

    sudo cmake --install build
}
