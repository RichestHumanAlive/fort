#ifndef IFACEPAGE_H
#define IFACEPAGE_H

#include "optbasepage.h"

QT_FORWARD_DECLARE_CLASS(QKeySequenceEdit)

class IfacePage : public OptBasePage
{
    Q_OBJECT

public:
    explicit IfacePage(OptionsController *ctrl = nullptr, QWidget *parent = nullptr);

    bool explorerEdited() const { return m_explorerEdited; }
    void setExplorerEdited(bool v) { m_explorerEdited = v; }

    bool languageEdited() const { return m_languageEdited; }
    void setLanguageEdited(bool v) { m_languageEdited = v; }

    bool themeEdited() const { return m_themeEdited; }
    void setThemeEdited(bool v) { m_themeEdited = v; }

public slots:
    void onResetToDefault() override;

protected slots:
    void onAboutToSave() override;
    void onEditResetted() override;

    void onRetranslateUi() override;

private:
    void retranslateComboTheme();
    void retranslateComboHotKey();
    void retranslateComboTrayEvent();
    void retranslateComboTrayAction();

    void setupUi();
    QLayout *setupColumn1();
    QLayout *setupColumn2();

    void setupGlobalBox();
    QLayout *setupLangLayout();
    void setupComboLanguage();
    QLayout *setupThemeLayout();
    void setupHotKeysBox();
    void refreshEditShortcut();
    QLayout *setupComboHotKeyLayout();
    QLayout *setupEditShortcutLayout();
    void setupHomeBox();
    void setupTrayBox();
    QLayout *setupTrayMaxGroupsLayout();
    void refreshComboTrayAction();
    QLayout *setupTrayEventLayout();
    QLayout *setupTrayActionLayout();
    void setupConfirmationsBox();

    void updateTheme();

private:
    bool m_explorerEdited : 1 = false;
    bool m_languageEdited : 1 = false;
    bool m_themeEdited : 1 = false;

    QGroupBox *m_gbGlobal = nullptr;
    QGroupBox *m_gbHotKeys = nullptr;
    QGroupBox *m_gbHome = nullptr;
    QGroupBox *m_gbTray = nullptr;
    QGroupBox *m_gbConfirmations = nullptr;

    QCheckBox *m_cbExplorerMenu = nullptr;
    QCheckBox *m_cbExcludeCapture = nullptr;
    QCheckBox *m_cbUseSystemLocale = nullptr;
    QLabel *m_labelLanguage = nullptr;
    QComboBox *m_comboLanguage = nullptr;
    QLabel *m_labelTheme = nullptr;
    QComboBox *m_comboTheme = nullptr;

    QCheckBox *m_cbHotKeysEnabled = nullptr;
    QCheckBox *m_cbHotKeysGlobal = nullptr;
    QLabel *m_labelHotKey = nullptr;
    QComboBox *m_comboHotKey = nullptr;
    QLabel *m_labelShortcut = nullptr;
    QKeySequenceEdit *m_editShortcut = nullptr;

    QCheckBox *m_cbHomeAutoShowMenu = nullptr;
    QCheckBox *m_cbSplashVisible = nullptr;
    QCheckBox *m_cbTrayShowIcon = nullptr;
    QCheckBox *m_cbTrayShowAlert = nullptr;
    QCheckBox *m_cbTrayAnimateAlert = nullptr;
    QLabel *m_labelTrayMaxGroups = nullptr;
    QSpinBox *m_spinTrayMaxGroups = nullptr;

    QLabel *m_labelTrayEvent = nullptr;
    QComboBox *m_comboTrayEvent = nullptr;
    QLabel *m_labelTrayAction = nullptr;
    QComboBox *m_comboTrayAction = nullptr;
    QCheckBox *m_cbConfirmTrayFlags = nullptr;
    QCheckBox *m_cbConfirmQuit = nullptr;
};

#endif // IFACEPAGE_H
