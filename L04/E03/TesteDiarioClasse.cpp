#include "DiarioClasse.hpp"
#include "doctest.h"

TEST_CASE("Teste 1 - Aprovação básica") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(60, 0, 0.75);
    CHECK(aprovado);
};

TEST_CASE("Teste 2 - Reprovação por nota") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(59, 0, 0.75);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 3 - Reprovação por frequência") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(60, 0, 0.74);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 4 - Aprovação no exame especial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(59, 60, 0.75);
    CHECK(aprovado);
}

TEST_CASE("Teste 5 - Reprovação no exame especial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(59, 59, 0.75);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 6 - Reprovação por nota < 40") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(39, 0, 0.75);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 7 - Nota semestre > 100") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(101, 0, 1), ExcecaoNotaSemestreInvalida);
}

TEST_CASE("Teste 8 - Nota semestre < 0") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(-1, 0, 1), ExcecaoNotaSemestreInvalida);
}

TEST_CASE("Teste 8 - Frequência > 1") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, 1.01), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 8 - Frequência < 0") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, -0.01), ExcecaoFrequenciaInvalida);
}