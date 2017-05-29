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
		// 4 cores * 5 discos (1bit pra cada)
		ll mtabuleiro :20;
		
		// 0..5 posições possíveis (3bits) * 5 peões
		ll mpeao :15;

		// 0..6 posições (3bits) * 5 peões
		ll mescada :15;
	};

	struct {
		// 0..6 discos (3bits) * 5 cores * 2 jogadores
		ll mjogadores :30;
		
		// Jogador 1 ou Jogador 2
		ll matual :1;
	};

	// RAII (Resource Aquisition is Initialization
	State(int _tabuleiro = (1<<20)-1, int _peao = 0, int _escada = 0, int _jogadores = 0, int _atual = 0)
		: mtabuleiro(_tabuleiro), mpeao(_peao), mescada(_escada), mjogadores(_jogadores), matual(_atual)
	{
	}

	// Read and set individual variables
	int tabuleiro (int pos) const { return (mtabuleiro & (1<<pos))>>pos; }
	void settabuleiro (int pos, int available) { mtabuleiro = (mtabuleiro & ~(1<<pos)) | ((available&1)<<pos); }

	int peao (int cor) const { return (mpeao & (7<<(3*cor)))>>(3*cor); }
	void setpeao (int cor, int pos) { mpeao = (mpeao&~(7<<(3*cor)))|((pos&7)<<(3*cor)); }
	void movepeao (int cor) { setpeao(cor,peao(cor)+1); }

	int escada (int cor) const { return (mescada & (7<<(3*cor)))>>(3*cor); }
	void setescada (int cor, int pos) { mescada = (mescada&~(7<<(3*cor)))|((pos&7)<<(3*cor)); }

	int jogador (int jogador, int cor) const { return ((mjogadores>>(15*jogador)) & (7<<(3*cor)))>>(3*cor);	}
	void setjogador (int jogador, int cor, int qtd) { mjogadores = (mjogadores & ~(7<<(3*cor + 15*jogador) )) | ((qtd & 7) << (3*cor + 15*jogador)); }
	void updatejogador (int player, int cor) { setjogador(player, cor, jogador(player, cor)+1); }

	int atual () const { return matual; }
	void updateatual () { matual ^= 1; }

	// Operator to use it in map
	bool operator<(const struct State& s) const {
		if (mtabuleiro != s.mtabuleiro) return mtabuleiro < s.mtabuleiro;
		if (mpeao != s.mpeao) return mpeao < s.mpeao;
		if (mescada != s.mescada) return mescada < s.mescada;
		if (mjogadores != s.mjogadores) return mjogadores < s.mjogadores;
		return matual < s.matual;
	}

	
};

#endif
