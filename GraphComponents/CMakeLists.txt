aux_source_directory(. GRAPH_SOURCE)
add_library(GraphComponents ${GRAPH_SOURCE} charger.cpp charger.h coordinates.cpp coordinates.h)