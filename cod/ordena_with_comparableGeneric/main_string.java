public class Main {
    public static void main(String[] args) {
        ArvoreBinaria<String> arvore = new ArvoreBinaria<String>();
        String[] lista = {"b", "v", "a", "h", "r", "w", "s", "f"};
        for (String valor : lista) {
            arvore.inserir(valor);
        }
        arvore.inOrder(arvore.raiz);
    }
}
