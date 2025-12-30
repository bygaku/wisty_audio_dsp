# test root
file(GLOB TEST_SRC CONFIGURE_DEPENDS "./*.cpp")
set(TEST_DSP "test_dsp")

enable_testing()
include(FetchContent)
FetchContent_Declare(
        GoogleTest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(GoogleTest)

# Add test process in below.
add_executable(${TEST_DSP}
        ${TEST_SRC}
)

# Add own library.
target_link_libraries(${TEST_DSP}
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        ${LIBRARY_NAME}
)

add_test(NAME t_audio_dsp
        COMMAND
        $<TARGET_FILE:${TEST_DSP}>
)

# Compiler options.
if(MSVC)
    target_compile_definitions(${TEST_DSP}
            PRIVATE
            UNICODE     # Unicode mode
            _UNICODE    # Multi-byte mode
            NOMINMAX
    )

    set_property(TARGET ${TEST_DSP}
            PROPERTY
            MSVC_CHARACTER_SET "Unicode"
    )   # use Unicode.

    add_compile_options(
            /utf-8      # using UTF-8
            /W4         # warning level: 4
            /wd4819     # suppression of character encoding warnings
            /TP         # all src file written by cxx.
    )
endif()
