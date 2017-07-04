#ifndef __STATE_H__
#define __STATE_H__

#include <vector>

using namespace std;

using ll = unsigned long long;

struct State
{
	// Cinco cores, quatro discos
	struct {
		// 5 cores * 4 discos (1bit pra cada)
		ll _tabuleiro :20;
		
		// 0..5 posições possíveis (3bits) * 5 peões
		ll _peao :15;

		// 0..5 posições (3bits) * 5 peões
		ll _escada :15;
	};

	struct {
		// 0..5 discos (3bits) * 5 cores * 2 jogadores
		ll _jogadores :30;
		
		// Jogador 1 ou Jogador 2 (quem fará a próxima jogada)
		ll _atual :1;
	};

	// RAII (Resource Aquisition is Initialization
	State(int mtabuleiro = (1<<20)-1, int mpeao = 0, int mescada = 0,
		int mjogadores = 0, int matual = 0)	: _tabuleiro(mtabuleiro),
		_peao(mpeao), _escada(mescada),	_jogadores(mjogadores),
		_atual(matual)
	{
	}

	// Read and set individual variables
	int tabuleiro (int pos) const {
		return (_tabuleiro & (1<<pos))>>pos;
	}
	
	void settabuleiro (int pos, int available) {
		_tabuleiro = (_tabuleiro & ~(1<<pos)) | ((available&1)<<pos);
	}


	int peao (int cor) const {
		return (_peao & (7<<(3*cor)))>>(3*cor);
	}
	
	void setpeao (int cor, int pos) {
		_peao = (_peao&~(7<<(3*cor)))|((pos&7)<<(3*cor));
	}
	
	void movepeao (int cor) {
		setpeao(cor,peao(cor)+1);
	}


	int escada (int cor) const {
		return (_escada & (7<<(3*cor)))>>(3*cor);
	}
	
	void setescada (int cor, int pos) {
		_escada = (_escada&~(7<<(3*cor)))|((pos&7)<<(3*cor));
	}

	
	int jogador (int jogador, int cor) const {
		return ((_jogadores>>(15*jogador)) & (7<<(3*cor)))>>(3*cor);
	}
	
	void setjogador (int jogador, int cor, int qtd) {
		_jogadores = (_jogadores & ~(7<<(3*cor + 15*jogador) ))
			| ((qtd & 7) << (3*cor + 15*jogador));
	}
	
	void updatejogador (int player, int cor) {
		setjogador(player, cor, jogador(player, cor)+1);
	}

	
	int atual () const {
		return _atual;
	}
	
	void updateatual () {
		_atual ^= 1;
	}


	// Operator to use it in map
	bool operator<(const struct State& s) const {
		if (_tabuleiro != s._tabuleiro) return _tabuleiro < s._tabuleiro;
		if (_peao != s._peao) return _peao < s._peao;
		if (_escada != s._escada) return _escada < s._escada;
		if (_jogadores != s._jogadores) return _jogadores < s._jogadores;
		return _atual < s._atual;
	}

	
};

#endif
