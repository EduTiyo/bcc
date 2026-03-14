package lab_selenium;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

import io.github.bonigarcia.wdm.WebDriverManager;

public class EnrolledSubjectsTest {
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

    portalPage.clickEnrolledSubjects();
    portalPage.waitForEnrolledSubjectsTable();
    String campusHeader = driver.findElement(By.xpath("//table[@class='tbl']//th[text()='Campus']")).getText();
    assertEquals("Campus", campusHeader, "Cabeçalho da tabela de disciplinas não encontrado.");
  }

  @AfterAll
  static void teardown() {
    if (driver != null) {
      driver.quit();
    }
  }
}
