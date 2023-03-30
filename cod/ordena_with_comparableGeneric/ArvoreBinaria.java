package ordenaarvore_comparable_generic;

class ArvoreBinaria<T extends Comparable<T>> {
    No<T> raiz;

    public ArvoreBinaria() {
        this.raiz = null;
    }

    public void inserir(T valor) {
        No<T> novoNo = new No<T>(valor);
        if (this.raiz == null) {
            this.raiz = novoNo;
        } else {
            No<T> noAtual = this.raiz;
            while (true) {
                if (valor.compareTo(noAtual.valor) < 0) {
                    if (noAtual.esquerdo == null) {
                        noAtual.esquerdo = novoNo;
                        break;
                    } else {
                        noAtual = noAtual.esquerdo;
                    }
                } else {
                    if (noAtual.direito == null) {
                        noAtual.direito = novoNo;
                        break;
                    } else {
                        noAtual = noAtual.direito;
                    }
                }
            }
        }
    }
    
    public void inOrder(No<T> no) {
        if (no != null) {
            inOrder(no.esquerdo);
            System.out.print(no.valor + " ");
            inOrder(no.direito);
        }
    }
}
