add_executable(${PROJECT_NAME})

set(GAME_SOURCES 
    main.cpp 
    dung.cpp 
    dung.h
    level/level_generator.cpp 
    level/level_generator.h)
target_sources(${PROJECT_NAME} PRIVATE ${GAME_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE engine)