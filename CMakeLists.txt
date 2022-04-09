cmake_minimum_required(VERSION 3.19)
project(PO_Proj1)

set(CMAKE_CXX_STANDARD 20)

add_executable(PO_Proj1 main.cpp World.cpp World.h Entity.cpp Entity.h RenderBatch.cpp RenderBatch.h Position.h Animal.cpp Animal.h Wolf.cpp Wolf.h Sheep.cpp Sheep.h Fox.cpp Fox.h Turtle.cpp Turtle.h Antelope.cpp Antelope.h Journal.cpp Journal.h Plant.cpp Plant.h Grass.cpp Grass.h Dandelion.cpp Dandelion.h Guarana.cpp Guarana.h Belladonna.cpp Belladonna.h Hogweed.cpp Hogweed.h Human.cpp Human.h IControllable.h InputKeyMap.h Serializer.cpp Serializer.h SerializationContext.cpp SerializationContext.h)