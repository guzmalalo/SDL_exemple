cmake_minimum_required(VERSION 3.10)

project(SDL_Project LANGUAGES C)

# Chemin vers le dossier SDL, ceci peut etre un chemin
# absolu comme C:\Users\toto\Downloads\SDL3-devel-3.1.6-mingw\SDL3-3.1.6
# cela permet de n'est pas renvoyer les sources de SDL vers github pour
# chaque projet
set(SDL3_DIR "external/SDL3-3.1.6/")
set(SDL3_HEADERS "external/SDL3-3.1.6/x86_64-w64-mingw32/include")

# On utilise les modules cmake pour trouver les
# *.h et les librairies associées
find_package(SDL3 REQUIRED PATHS ${SDL3_DIR})

# Pogramme principal
add_executable(app main.c)

# On inclue les *.h de SDL 3 dans notre projet
target_include_directories(app PRIVATE SDL3::Headers)

# On inclue les libraries compilées de SDL dans notre projet
target_link_libraries(app PRIVATE SDL3::SDL3)
target_link_options(app PRIVATE -static)