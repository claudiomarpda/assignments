# entropy_analysis
Sorting vectors with different entropy level <br/>
Languages: C++ and Java

No exercício anterior, vocês implementaram os algoritmos de ordenação por comparação mais comuns. Nas aulas teóricas, vocês estudaram a análise da complexidade assintótica dos mesmos. Neste exercício puramente experimental, vocês verão os efeitos das complexidades na prática.

São fornecidos três subconjuntos de entradas (link), diferindo quanto ao grau de ordenação das mesmas:

Subconjunto 1: vetores 10% ordenados (90% de entropia).
Subconjunto 2: vetores 50% ordenados (50% de entropia).
Subconjunto 3: vetores 90% ordenados (10% de entropia).
Cada subconjunto apresenta vetores de diferentes tamanhos gerados aleatoriamente utilizando diferentes sementes. Assim, será possível analisar os efeitos do tamanho e do tipo do subconjunto, tendo em mãos uma amostragem de tamanho razoável para propósitos estatísticos.

Dadas as implementações do exercício anterior e os conjuntos de entradas fornecidos para este exercício:

Selecione um colega que tenha implementado os algoritmos de ordenação usando uma linguagem de programação diferente da sua.
Para cada subconjunto de entrada, execute todos os algoritmos e calcule o tempo médio que cada algoritmo gasta para cada tamanho presente no subconjunto.
A pontuação deste trabalho será dividida da seguinte forma:

Análise do tempo de execução de cada algoritmo (0,5 ponto para cada aluno).
Análise comparativa entre os dois conjuntos de implementações e uma implementação padrão de ordenação fornecida nas linguagens escolhidas (0,5 ponto para a dupla).
A análise deverá ser fornecida em formato a ser escolhido pela dupla (relatório, prezi ou slides em vídeo). Torne o “produto” conciso, porém interessante. Os seguintes tipos de análise são sugeridos:

Para cada subconjunto de entradas, faça um gráfico demonstrando o crescimento do tempo de execução médio ao longo do aumento dos tamanhos dos vetores.
Para um determinado tamanho de entrada, faça um gráfico demonstrando a variação (potencialmente o crescimento) do tempo de execução médio ao longo do aumento do grau de entropia dos vetores (diferentes subconjuntos).
Ao comparar com o método padrão fornecido pela linguagem escolhida, explique o funcionamento deste método e porque ele é (in)eficiente.
Uma vez que este exercício exigirá um maior esforço computacional, seu prazo será maior do que o dos demais.

Todos os experimentos devem ser executados em cores (núcleos) de um mesmo computador.
Caso algum algoritmo demore mais que 5 minutos para uma dada entrada, desconsidere este algoritmo para o restante do subconjunto em questão (tamanhos iguais ou maiores que o da entrada em questão).
Se optar pelo formato relatório, a dupla deve enviá-lo em PDF por email. Caso opte pelos formatos Prezi ou Slides em vídeo, a dupla deve enviar o link do Prezi ou do vídeo no servidor escolhido (YouTube, Vimeo, …).
