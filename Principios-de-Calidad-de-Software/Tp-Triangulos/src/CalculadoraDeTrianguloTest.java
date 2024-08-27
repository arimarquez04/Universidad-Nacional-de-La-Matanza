import org.junit.Test;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;

import static org.junit.jupiter.api.Assertions.*;

public class CalculadoraDeTrianguloTest {
    private static CalculadoraDeTriangulo calculadora;

    @Test
    public void testTrianguloEquilatero() {
        calculadora = new CalculadoraDeTriangulo();
        // Caso 1: Triángulo equilátero (todos los lados iguales)
        calculadora.setLadoA(5.0);
        calculadora.setLadoB(5.0);
        calculadora.setLadoC(5.0);
        assertEquals("Equilatero", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloIsosceles() {
        calculadora = new CalculadoraDeTriangulo();
        // Caso 2: Triángulo isósceles (dos lados iguales)
        calculadora.setLadoA(5.0);
        calculadora.setLadoB(5.0);
        calculadora.setLadoC(3.0);
        assertEquals("Isosceles", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloEscaleno() {
        calculadora = new CalculadoraDeTriangulo();
        // Caso 3: Triángulo escaleno (todos los lados diferentes)
        calculadora.setLadoA(3.0);
        calculadora.setLadoB(4.0);
        calculadora.setLadoC(5.0);
        assertEquals("Escaleno", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testNoEsTriangulo() {
        calculadora = new CalculadoraDeTriangulo();
        // Caso 4: No es un triángulo válido (violación de la desigualdad triangular)
        calculadora.setLadoA(1.0);
        calculadora.setLadoB(2.0);
        calculadora.setLadoC(3.0);
        assertEquals("No es un triangulo valido", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloIsoscelesOtraConfiguracion() {
        calculadora = new CalculadoraDeTriangulo();
        // Caso 5: Triángulo isósceles con otra configuración (dos lados iguales)
        calculadora.setLadoA(7.0);
        calculadora.setLadoB(7.0);
        calculadora.setLadoC(10.0);
        assertEquals("Isosceles", calculadora.determinarTipoTriangulo());
    }
}