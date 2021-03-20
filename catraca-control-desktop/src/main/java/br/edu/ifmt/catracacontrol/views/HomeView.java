package br.edu.ifmt.catracacontrol.views;

import br.edu.ifmt.catracacontrol.controllers.HomeController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.FileInputStream;
import java.io.IOException;

public class HomeView extends Application {

  @Override public void start(Stage stage) throws Exception {
    try {
      var view = new FXMLLoader();
      Parent parent = view.load(new FileInputStream("src/main/resources/views/home.fxml"));
      HomeController controller = view.getController();
      controller.setStage(stage);
      stage.setScene(new Scene(parent));
      stage.setTitle("CATRACA $ISTEM");
      stage.setResizable(false);
      stage.show();
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}