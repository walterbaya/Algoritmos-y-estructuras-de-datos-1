#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(PuntajeTest, MenorQueDiezNoDivisiblePor3){
    int puntos = puntaje(5);
    EXPECT_EQ(puntos,0);
}
TEST(PuntajeTest, MayorQueDiezDivisiblePor3){
    int puntos = puntaje(15);
    EXPECT_EQ(puntos,25);
}