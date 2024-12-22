import quads.*;

public class Quadritc {
        public static void main(String[] args) {
            
            QuadraticSolver solver = QuadraticSolver.getSolver();
    
            double a = 1;
            double b = -3;
            double c = 2;

            System.out.println("Quadratic equation: " + a + "x^2 + " + b + "x + " + c);
    
            solver.solve(a, b, c);
        }
}
