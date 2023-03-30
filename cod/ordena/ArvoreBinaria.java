class ArvoreBinaria {
    No raiz;

    public ArvoreBinaria() {
        this.raiz = null;
    }

    public void inserir(int valor) {
        No novoNo = new No(valor);
        if (this.raiz == null) {
            this.raiz = novoNo;
        } else {
            No noAtual = this.raiz;
            while (true) {
                if (valor < noAtual.valor) {
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
	  public void inOrder(No no) {
		if (no != null) {
            		inOrder(no.esquerdo);
            		System.out.print(no.valor + " ");
            		inOrder(no.direito);
        }
    }
}
