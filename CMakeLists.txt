cmake_minimum_required(VERSION 4.0)
project(BreadEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include SDL3
set(SDL3_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")
set(SDL3_DLL "${SDL3_DIR}/lib/x64/SDL3.dll")

add_library(SDL3 SHARED IMPORTED)
set_target_properties(SDL3 PROPERTIES
        IMPORTED_IMPLIB "${SDL3_DIR}/lib/x64/SDL3.lib"
        IMPORTED_LOCATION "${SDL3_DLL}"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL3_DIR}/include"
)
link_libraries(SDL3)

# include SDL3_image
set(SDL3_image_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3_image-3.2.0")
set(SDL3_image_DLL "${SDL3_image_DIR}/lib/x64/SDL3_image.dll")

add_library(SDL3_image SHARED IMPORTED)
set_target_properties(SDL3_image PROPERTIES
        IMPORTED_IMPLIB "${SDL3_image_DIR}/lib/x64/SDL3_image.lib"
        IMPORTED_LOCATION "${SDL3_image_DIR}"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL3_image_DIR}/include"
)
link_libraries(SDL3_image)

# include SDL3_ttf
set(SDL3_ttf_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3_ttf-3.2.0")
set(SDL3_ttf_DLL "${SDL3_ttf_DIR}/lib/x64/SDL3_ttf.dll")

add_library(SDL3_ttf SHARED IMPORTED)
set_target_properties(SDL3_ttf PROPERTIES
        IMPORTED_IMPLIB "${SDL3_ttf_DIR}/lib/x64/SDL3_ttf.lib"
        IMPORTED_LOCATION "${SDL3_ttf_DLL}"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL3_ttf_DIR}/include"
)
link_libraries(SDL3_ttf)


file(GLOB SOURCES "SDL3Game/*.cpp")
file(GLOB SCENESOURCES "SDL3Game/Scenes/*.cpp")
add_executable(BreadEngine SDL3Game/main.cpp
        ${SOURCES}
        ${SCENESOURCES}
)

include_directories("${CMAKE_SOURCE_DIR}/libs/json")


# for static linking
if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
endif()
if(WIN32)
    target_link_libraries(BreadEngine PRIVATE kernel32 user32 gdi32)
endif()


# добавляем dll в папку с exe, если на винде
if (WIN32)
    set(DLL_LIST
            ${SDL3_DLL}
            ${SDL3_image_DLL}
            ${SDL3_ttf_DLL}
    )
    foreach(DLL ${DLL_LIST})
        add_custom_command(TARGET BreadEngine POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${DLL}"
                "$<TARGET_FILE_DIR:BreadEngine>"
        )
    endforeach()

endif ()

add_custom_command(TARGET BreadEngine PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/SDL3Game/assets $<TARGET_FILE_DIR:BreadEngine>/assets)