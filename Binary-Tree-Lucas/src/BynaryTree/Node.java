package BynaryTree;

public class Node<T extends Comparable> {
    private T valor;
    private Node esq, dir;

    public Node(T valor){
        this.valor = valor;
        this.esq = null;
        this.dir = null;
    }
    public Node getEsq(){
        return this.esq;
    }
    public void setEsq(Node<T> no){
        this.esq = no;
    }
    public Node getDir(){
        return this.dir;
    }
    public void setDir(Node<T> no){
        this.dir = no;
    }
    public T getValor(){
        return this.valor;
    }
}
