package br.com.CebolaMusic;

public class Podcasts extends Audio{
    private String descricao;
    private String host;

    public String getDescricao() {
        return descricao;
    }
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getHost() {
        return host;
    }
    public void setHost(String host) {
        this.host = host;
    }
}
