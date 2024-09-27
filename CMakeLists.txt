cmake_minimum_required(VERSION 3.13)
project(your_project C ASM)

# Указываем кросс-компилятор
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

# Указываем флаги компиляции и линковки
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -O2 -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-T STM32F4xx.ld -Wl,-Map=output.map")

# Пути к заголовочным файлам (все в корневой папке)
include_directories(
    .
)

# Список исходных файлов
set(SOURCES
    main.c
    startup_stm32f4xx.s
    system_stm32f4xx.c
    stm32f4xx_hal.c
)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Создаем бинарный файл после сборки
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMENT "Генерация бинарного файла"
)
