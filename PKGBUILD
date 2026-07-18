# Maintainer: therealmaksim4
pkgname="workflow"
pkgver=0.0.1121
pkgrel=1
pkgdesc="Enhance your coding"
arch=("x86_64")
url="https://github.com/therealmaksim4/workflow"
license=("GPL")
depends=()
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
