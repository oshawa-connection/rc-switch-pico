add_executable(receive
        Receive.cc
        ../../radio-switch.cc
        )


add_compile_options(-Wall
-Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
-Wno-unused-function # we have some for the docs that aren't called
-Wno-maybe-uninitialized
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(receive pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(receive 1)
pico_enable_stdio_uart(receive 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(receive)
