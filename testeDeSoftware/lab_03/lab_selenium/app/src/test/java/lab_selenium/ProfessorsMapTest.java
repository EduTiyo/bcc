package lab_selenium;

import io.github.bonigarcia.wdm.WebDriverManager;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class ProfessorsMapTest {
  private static WebDriver driver;
  private static LoginPage loginPage;

  @BeforeAll
  static void setup() {
    WebDriverManager.firefoxdriver().create();
    driver = new FirefoxDriver();
    loginPage = new LoginPage(driver);
  }

  @Test
  void shouldNavigateToLoginPage(){
    loginPage.navigateTo();
    assertEquals("Autenticação", loginPage.getTitle(), "Título da página de login não corresponde ao esperado.");
  }
  
  @Test
  void shouldNavigateToProfessorsMap() {
    String usuario = "a2551748";
    String senha = "eduknabben16";

    loginPage.navigateTo();
    HomePage homePage = loginPage.doLogin(usuario, senha);

    assertEquals("Portal do Aluno", homePage.getHomePageTitleText(), "Título da página após o login não corresponde ao esperado.");

    PortalDoAlunoPage portalPage = homePage.navigateToCampusPage();
    assertEquals("Portal do Aluno - Campo Mourão", portalPage.getPageTitle(), "Título da página do portal do aluno não corresponde ao esperado.");

    portalPage.clickProfessorsMap();
    assertEquals("Mapa de Professor", portalPage.getSectionTitle(), "Título da seção do mapa de professores não corresponde ao esperado.");

    portalPage.selectDepartment("2214", "DACOM");
    portalPage.selectProfessor("1506","REGINALDO RE - Reginaldo Re");
    portalPage.clickSearchButton();
    assertEquals("Mapa de Aulas e Permanências - 2025/2", portalPage.waitForMapaDeAulasEPermanencias(), "Título da página do mapa de aulas e permanências não corresponde ao esperado.");
  }

  @AfterAll
  static void teardown() {
    if (driver != null) {
      driver.quit();
    }
  }
}
