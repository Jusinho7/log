#!/bin/bash

# ============================================================
#   Script d'installation - Environnement de développement
#   Compatible : Pop!_OS, Ubuntu, Debian
#   Auteur     : généré avec Claude
# ============================================================

set -e  # Arrête le script si une commande échoue

# Couleurs
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

ok()   { echo -e "${GREEN}✅ $1${NC}"; }
info() { echo -e "${BLUE}➡️  $1${NC}"; }
warn() { echo -e "${YELLOW}⚠️  $1${NC}"; }
fail() { echo -e "${RED}❌ $1${NC}"; }

echo ""
echo -e "${BLUE}============================================${NC}"
echo -e "${BLUE}   Installation de l'environnement dev      ${NC}"
echo -e "${BLUE}============================================${NC}"
echo ""

# ------------------------------------------------------------
# 1. Mise à jour du système
# ------------------------------------------------------------
info "Mise à jour du système..."
sudo apt update && sudo apt upgrade -y
ok "Système à jour"

# ------------------------------------------------------------
# 2. Outils de base
# ------------------------------------------------------------
info "Installation des outils de base (git, curl, wget, etc.)..."
sudo apt install -y \
  git curl wget unzip vim nano htop \
  build-essential make cmake
ok "Outils de base installés"

# ------------------------------------------------------------
# 3. Python
# ------------------------------------------------------------
info "Installation de Python..."
sudo apt install -y python3 python3-dev python3-venv python3-full
ok "Python $(python3 --version) installé"

# pipx (pour les outils CLI Python sans casser le système)
info "Installation de pipx..."
sudo apt install -y pipx
pipx ensurepath
ok "pipx installé"

# Outils 42
info "Installation de norminette et c_formatter_42..."
pipx install norminette
pipx install c_formatter_42
ok "norminette et c_formatter_42 installés"

# Venv global pour les packages Python perso
info "Création d'un environnement virtuel Python global (~/.venv)..."
python3 -m venv ~/.venv
# Activation automatique dans le shell
if ! grep -q "source ~/.venv/bin/activate" ~/.bashrc; then
  echo '' >> ~/.bashrc
  echo '# Venv Python global' >> ~/.bashrc
  echo 'source ~/.venv/bin/activate' >> ~/.bashrc
fi

# Packages pip utiles
info "Installation des packages Python utiles..."
~/.venv/bin/pip install --upgrade pip
~/.venv/bin/pip install \
  black \
  flake8 \
  pylint \
  mypy \
  pytest \
  ipython \
  requests \
  rich \
  virtualenv
ok "Packages Python installés"

# ------------------------------------------------------------
# 4. Java (OpenJDK)
# ------------------------------------------------------------
info "Installation de Java (OpenJDK)..."
sudo apt install -y default-jdk
ok "Java $(java -version 2>&1 | head -1) installé"

# ------------------------------------------------------------
# 5. C / C++ / GDB
# ------------------------------------------------------------
info "Installation de C / C++ / GDB..."
sudo apt install -y gcc g++ gdb
ok "GCC $(gcc --version | head -1 | cut -d' ' -f4) installé"

# ------------------------------------------------------------
# 6. C# (.NET SDK)
# ------------------------------------------------------------
info "Installation de C# (.NET SDK 8)..."
sudo apt install -y dotnet-sdk-8.0 2>/dev/null || {
  warn "Tentative d'installation via le repo Microsoft..."
  wget -q "https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb" \
    -O /tmp/ms-prod.deb
  sudo dpkg -i /tmp/ms-prod.deb 2>/dev/null || true
  sudo apt update -qq
  sudo apt install -y dotnet-sdk-8.0
}
ok "C# .NET $(dotnet --version) installé"

# ------------------------------------------------------------
# 7. PHP
# ------------------------------------------------------------
info "Installation de PHP..."
sudo apt install -y php php-cli php-curl php-mbstring php-xml php-zip php-mysql
ok "$(php --version | head -1) installé"

# ------------------------------------------------------------
# 8. MariaDB
# ------------------------------------------------------------
info "Installation de MariaDB..."
sudo apt install -y mariadb-server mariadb-client
sudo systemctl enable mariadb
sudo systemctl start mariadb
ok "MariaDB $(mysql --version | awk '{print $5}') installé"
warn "Pense à lancer 'sudo mysql_secure_installation' pour sécuriser MariaDB"

# ------------------------------------------------------------
# 9. Node.js (via nvm)
# ------------------------------------------------------------
info "Installation de Node.js via nvm..."
export NVM_DIR="$HOME/.nvm"
if [ ! -d "$NVM_DIR" ]; then
  curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
fi
# Charger nvm
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
nvm install --lts
ok "Node.js $(node --version) installé via nvm"

# ------------------------------------------------------------
# 10. Go
# ------------------------------------------------------------
info "Installation de Go..."
sudo apt install -y golang
ok "$(go version) installé"

# ------------------------------------------------------------
# 11. Rust
# ------------------------------------------------------------
info "Installation de Rust..."
if ! command -v rustc &> /dev/null; then
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
  source "$HOME/.cargo/env"
  if ! grep -q 'source "$HOME/.cargo/env"' ~/.bashrc; then
    echo 'source "$HOME/.cargo/env"' >> ~/.bashrc
  fi
fi
ok "$(rustc --version) installé"

# ------------------------------------------------------------
# 12. Ruby
# ------------------------------------------------------------
info "Installation de Ruby..."
sudo apt install -y ruby ruby-dev
ok "$(ruby --version | cut -d' ' -f1-2) installé"

# ------------------------------------------------------------
# 13. SQLite
# ------------------------------------------------------------
info "Installation de SQLite..."
sudo apt install -y sqlite3 libsqlite3-dev
ok "SQLite $(sqlite3 --version | cut -d' ' -f1) installé"

# ------------------------------------------------------------
# Résumé final
# ------------------------------------------------------------
echo ""
echo -e "${BLUE}============================================${NC}"
echo -e "${GREEN}   ✅ Installation terminée !               ${NC}"
echo -e "${BLUE}============================================${NC}"
echo ""
echo "🐍 Python       : $(python3 --version)"
echo "☕ Java         : $(java -version 2>&1 | head -1)"
echo "⚙️  GCC (C)      : $(gcc --version | head -1 | cut -d' ' -f4)"
echo "⚙️  G++ (C++)    : $(g++ --version | head -1 | cut -d' ' -f4)"
echo "🔵 C# .NET      : $(dotnet --version)"
echo "🐘 PHP          : $(php --version | head -1 | cut -d' ' -f2)"
echo "🗃️  MariaDB      : $(mysql --version | awk '{print $5}')"
echo "🟢 Node.js      : $(node --version 2>/dev/null || echo 'relancer le terminal')"
echo "🐹 Go           : $(go version | cut -d' ' -f3)"
echo "🦀 Rust         : $(rustc --version | cut -d' ' -f2)"
echo "💎 Ruby         : $(ruby --version | cut -d' ' -f2)"
echo "🗄️  SQLite       : $(sqlite3 --version | cut -d' ' -f1)"
echo "📏 norminette   : $(norminette --version | head -1)"
echo "🎨 c_formatter  : pipx ✅"
echo ""
echo -e "${YELLOW}⚠️  Relance ton terminal (ou 'source ~/.bashrc') pour activer tous les outils.${NC}"
echo ""
