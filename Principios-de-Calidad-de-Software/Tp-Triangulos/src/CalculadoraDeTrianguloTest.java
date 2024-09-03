import org.junit.Test;
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
    @Test
    public void testTrianguloEquilateroLadosGrandes() {
        // Caso 6: Triángulo equilátero con lados grandes
        calculadora = new CalculadoraDeTriangulo();
        calculadora.setLadoA(1000.0);
        calculadora.setLadoB(1000.0);
        calculadora.setLadoC(1000.0);
        assertEquals("Equilatero", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloIsoscelesLadosPequenos() {
        // Caso 7: Triángulo isósceles con lados pequeños
        calculadora = new CalculadoraDeTriangulo();
        calculadora.setLadoA(0.5);
        calculadora.setLadoB(0.5);
        calculadora.setLadoC(0.3);
        assertEquals("Isosceles", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloEscalenoDecimales() {
        // Caso 8: Triángulo escaleno con lados decimales
        calculadora = new CalculadoraDeTriangulo();
        calculadora.setLadoA(3.5);
        calculadora.setLadoB(4.8);
        calculadora.setLadoC(5.1);
        assertEquals("Escaleno", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testTrianguloEquilateroConCeros() {
        // Caso 9: No es un triángulo válido (un lado es 0)
        calculadora = new CalculadoraDeTriangulo();
        calculadora.setLadoA(0.0);
        calculadora.setLadoB(5.0);
        calculadora.setLadoC(5.0);
        assertEquals("Lado invalido", calculadora.determinarTipoTriangulo());
    }

    @Test
    public void testNoEsTrianguloValoresNegativos() {
        // Caso 10: No es un triángulo válido (valores negativos)
        calculadora = new CalculadoraDeTriangulo();
        calculadora.setLadoA(-3.0);
        calculadora.setLadoB(4.0);
        calculadora.setLadoC(5.0);
        assertEquals("Lado invalido", calculadora.determinarTipoTriangulo());
    }
}