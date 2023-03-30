public class Main {
    public static void main(String[] args) {
        ArvoreBinaria arvore = new ArvoreBinaria();
        int[] lista = {3, 1, 4, 2, 6, 9, 7, 8, 5};
        for (int valor : lista) {
            arvore.inserir(valor);
        }
        arvore.inOrder(arvore.raiz); // imprime "1 2 3 4 5 6 7 8 9 "
    }
}
