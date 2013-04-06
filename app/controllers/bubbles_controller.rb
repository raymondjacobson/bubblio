class BubblesController < ApplicationController
  def new
  	@bubble = Bubble.new
  end

  def show
  	@bubble = Bubble.find(params[:id])
  end

  def create
  	@bubble = Bubble.new(params[:bubble])
  	if (@bubble.save)
  		flash[:success] = "Bubble Created!"
  		redirect_to bubble_path(@bubble)
  	else
  		render 'new'
  	end
  end

end
