package BynaryTree;
public class BynaryTree<T extends Comparable <T>>{
    private Node<T> prim;
    private int folhas;

    public BynaryTree(){
        this.prim = null;
        this.folhas = 0;
    }

    public Node getPrim(){
        return this.prim;
    }

    public void insert(T elem){
        Node<T> novo = new Node<T>(elem);
        Node<T> noatual = this.getPrim();
        boolean parar = false;

        if(noatual == null){
            this.prim = novo;
        }
        else{
            while(!parar){
                if(novo.getValor().compareTo(noatual.getValor()) < 0){
                    //noatual = noatual.getEsq();
                    if(noatual.getEsq() == null){
                        noatual.setEsq(novo);
                        parar = true;
                    }else{
                        noatual = noatual.getEsq();
                    }
                } else if (novo.getValor().compareTo(noatual.getValor()) > 0) {
                    //noatual = noatual.getEsq();
                    if(noatual.getDir() == null){
                        noatual.setDir(novo);
                        parar = true;
                    }else{
                        noatual = noatual.getDir();
                    }
                }
                else{
                    System.out.printf("Valor %s ja existe na arvore.", noatual.getValor().toString()
                    );
                }
            }
        }
    }

    public boolean search(T elem){
        boolean foundit = false;
        boolean parar = false;
        Node<T> searchto = new Node<T>(elem);
        Node<T> noatual = this.getPrim();

        if(noatual != null){
            while(!parar){
                if(searchto.getValor().compareTo(noatual.getValor()) < 0){
                    noatual = noatual.getEsq();
                    if(noatual.getValor() == null){
                        parar = true;
                    }
                }                    }
                } else if (searchto.getValor().compareTo(noatual.getValor()) > 0) {
                    noatual = noatual.getDir();
                    if(noatual.getValor() == null){
                        parar = true;
                    }
                }
                else{
                    foundit = true;
                    parar = true;
                }
        return foundit;
    }
}