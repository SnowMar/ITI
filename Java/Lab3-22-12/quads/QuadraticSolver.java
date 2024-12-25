package quads;

@FunctionalInterface
public interface QuadraticSolver {
    void solve(double a, double b, double c);

    static QuadraticSolver getSolver() {
        return (a, b, c) -> {
            double discriminant = b * b - 4 * a * c;
            if (discriminant >= 0) {
                double root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
                double root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
                System.out.println("Root 1: " + root1);
                System.out.println("Root 2: " + root2);
            } else {
                System.out.println("No real roots (discriminant is negative).");
            }
        };
    }
}
