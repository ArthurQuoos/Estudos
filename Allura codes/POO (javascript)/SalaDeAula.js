
const user = {   //inicio
    nome: 'Juliana\n',
    email: 'j@j.com',
    nascimento: '2024-01-01',
    role: 'estudante',
    ativo: true,
    exibirInfos: function() {
        console.log(this.nome, this.email);
    },
}

//user.exibirInfos();


const exibir = function() {
    console.log(this.nome, this.email); //funcionamento de this
}

const exibirNome = exibir.bind(user);
exibirNome();


/*
function exibeInfos() {      //exemplo de Call
    console.log(this.nome, this.email)
   };
   
   const user = {
    nome: 'Mariana',
    email: 'm@m.com',
   };
   
   exibeInfos.call(user);
   */

   /*
   function User(nome, email) {     //exemplo de Call 2
    this.nome = nome
    this.email = email
   
    this.exibeInfos = function(){
      console.log(this.nome, this.email)
    }
   }
   
   const newUser = new User('mariana', 'm@m.com')

   const outroUser = {
    nome: 'Rodrigo',
    email: 'r@r.com'
   }
   
   newUser.exibeInfos() //mariana m@m.com
   newUser.exibeInfos.call(outroUser) //Rodrigo r@r.com
   */

   /*
   function exibeMensagem(nome, email) {     //exemplo de Call 3
    console.log(`usuário: ${nome}, email ${email}`)
   }
    const user = {
    nome: 'Mariana',
    email: 'm@m.com',
    executaFuncao: function(fn) {
      fn.call(user, this.nome, this.email)
    }
   }
   
   user.executaFuncao(exibeMensagem) //usuário: Mariana, email m@m.com
   */

/*
   function exibeMensagem(nome, email) {
    console.log(`usuário: ${nome}, email ${email}`)   //exeplo de apply (apply e como call mas com array e nao string)
   }
    const user = {
    nome: 'Mariana',
    email: 'm@m.com',
    executaFuncao: function(fn) {
      fn.apply(user, [this.nome, this.email])
    }
   }
    user.executaFuncao(exibeMensagem) //usuário: Mariana, email m@m.com
*/

