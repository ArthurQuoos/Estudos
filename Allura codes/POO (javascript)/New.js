function User (nome, email) { //function construtora //User maiusculo
  this.nome = nome;
  this.email = email;

  this.exibirInfos = function() {
    return `${this.nome}, ${this.email}` //console.log
  }
}

const novoUser = new User('Juliana', 'j@j.com')
console.log(novoUser.exibirInfos());