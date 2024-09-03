public class CalculadoraDeTriangulo {
    private Double ladoA;
    private Double ladoB;
    private Double ladoC;

    public Double getLadoA() {
        return ladoA;
    }

    public void setLadoA(Double ladoA) {
        this.ladoA = ladoA;
    }

    public Double getLadoB() {
        return ladoB;
    }

    public void setLadoB(Double ladoB) {
        this.ladoB = ladoB;
    }

    public Double getLadoC() {
        return ladoC;
    }

    public void setLadoC(Double ladoC) {
        this.ladoC = ladoC;
    }

    public String determinarTipoTriangulo(Double ladoA, Double ladoB, Double ladoC) {
        if(ladoA<=0 || ladoB<=0 || ladoC<=0){
            return "Lado invalido";
        }
        // Verificamos si es un triángulo válido
        if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA) {
            if (ladoA.equals(ladoB) && ladoB.equals(ladoC)) {
                return "Equilatero";
            } else if (ladoA.equals(ladoB) || ladoA.equals(ladoC) || ladoB.equals(ladoC)) {
                return "Isosceles";
            } else {
                return "Escaleno";
            }
        } else {
            return "No es un triangulo valido";
        }
    }
    public String determinarTipoTriangulo() {
        if(ladoA<=0 || ladoB<=0 || ladoC<=0){
            return "Lado invalido";
        }
        // Verificamos si es un triángulo válido
        if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA) {
            if (ladoA.equals(ladoB) && ladoB.equals(ladoC)) {
                return "Equilatero";
            } else if (ladoA.equals(ladoB) || ladoA.equals(ladoC) || ladoB.equals(ladoC)) {
                return "Isosceles";
            } else {
                return "Escaleno";
            }
        } else {
            return "No es un triangulo valido";
        }
    }


}
