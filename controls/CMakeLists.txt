set(CONTROLS_SOURCES
    main.cpp
    input.cpp
)

add_executable(controls ${CONTROLS_SOURCES})

target_link_libraries(controls PRIVATE SFML::Graphics)