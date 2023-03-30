package ordenaarvore_comparable_generic;

class No<T extends Comparable<T>> {
    T valor;
    No<T> esquerdo;
    No<T> direito;

    public No(T valor) {
        this.valor = valor;
        this.esquerdo = null;
        this.direito = null;
    }
}
