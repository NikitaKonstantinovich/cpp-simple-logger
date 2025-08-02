# cmake/CompilerWarnings.cmake
# ───────────────────────────
# Подключает типовой набор предупреждений.
# Можно расширять по мере необходимости.

function(enable_default_warnings)
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(
            -Wall -Wextra -Wpedantic
            # -Werror         # ← сделайте ошибками при желании
        )
    elseif (MSVC)
        add_compile_options(/W4 /permissive-)
    endif()
endfunction()
