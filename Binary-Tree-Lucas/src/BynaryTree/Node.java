package BynaryTree;

public class Node<T> {
    private T valor;
    private Node prox;

    public Node(T valor){
        this.valor = valor;
        this.prox = null;
    }
}
