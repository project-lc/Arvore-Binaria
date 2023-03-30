package ordenaarvore_comparable_generic;

public class Main {
    public static void main(String[] args) {
        ArvoreBinaria<Integer> arvore = new ArvoreBinaria<Integer>();
        Integer[] lista = {90,43,57,82,13,1,9,55};
        for (Integer valor : lista) {
            arvore.inserir(valor);
        }
        arvore.inOrder(arvore.raiz);
    }
}
