# Global Solution
## Integrantes:
- Eduardo Dallabella Lima - rm556803
- Heloísa Real - rm554535
  
# 🐢 TrutleSea 🐢
--
O vazamento de óleo em oceanos e corpos d’água representam uma das ameaças mais graves aos ecossistemas aquáticos. Esses incidentes causam danos à fauna e flora, comprometendo a qualidade da água, animais marinhos, e também  afetando negativamente as comunidades humanas que dependem desses recursos. A dificuldade em detectar vazamentos de óleo rapidamente agrava o problema, pois a resposta tardia aumenta os danos ambientais e eleva os custos de limpeza e mitigação. Diante desse cenário, a necessidade de uma solução eficiente para a detecção precoce de vazamentos de óleo é crucial para a preservação do meio ambiente e a sustentabilidade dos recursos naturais.

Resumo da solução:
--
Dado o crescente e agravante problema dos vazamentos de óleo nos últimos anos, um estudo publicado na revista Science aponta esse dado e afirma: o acúmulo de óleo no oceano representa o "mais grave desastre ambiental". Em resposta a essa grave questão, foram exploradas diversas soluções e estudados possíveis contornos para desenvolver uma solução adequada. Foi decidido em nosso grupo criar um robô capaz de identificar a presença de óleo nos oceanos, utilizando um sensor infravermelho como fonte de identificação principal, ele será responsável por analisar a divergência entre o óleo e a água e notificar a presença no ambiente.

# Descrição do Código

## Definição de Pinos
- `INFRAVERMELHO_PIN` (A0): Sensor de infravermelho.
- `TRIG_DISTANCIA_PIN` (9): Pino de trigger para o sensor ultrassônico.
- `ECHO_DISTANCIA_PIN` (10): Pino de eco para o sensor ultrassônico.
- `VELOCIDADE_PIN` (A1): Pino analógico para o potenciômetro.
- `CONTROLADOR_DIST_PIN` (6): Pino PWM para controle do motor.

## Setup
- Inicialização da comunicação serial com baud rate de 9600.
- Configuração dos pinos como entrada ou saída conforme necessário.

## Loop
- Leitura da densidade de óleo simulada pelo sensor infravermelho.
- Cálculo da porcentagem com base na leitura do sensor.
- Leitura da distância pelo sensor ultrassônico e conversão para centímetros.
- Leitura do valor do potenciômetro e mapeamento para a velocidade do motor.
- Verificação de obstáculos à frente e parada do motor se a distância for inferior a 10 cm.
- Atraso de 500 milissegundos antes da próxima leitura.

# Link do wokwi
- https://wokwi.com/projects/399811140590535681
