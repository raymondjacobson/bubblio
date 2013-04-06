class ApplicationController < ActionController::Base
  protect_from_forgery

  def bubble_owns_item
  	@bubble = Bubble.find_by_id(params[:bubble_id] || params[:id])
  end

  def bubble_owns_link
  	@bubble = Bubble.find_by_id(params[:bubble_id] || params[:id])
  end

end
